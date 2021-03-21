package com.streamflowsolutions.streamflow.media.kurento;

import com.streamflowsolutions.streamflow.media.kurento.messages.bi.IceCandidateMessage;
import com.streamflowsolutions.streamflow.media.kurento.messages.bi.StopCommunicationMessage;
import com.streamflowsolutions.streamflow.media.kurento.messages.in.StartStreamMessage;
import com.streamflowsolutions.streamflow.media.kurento.messages.in.StartWatchMessage;
import com.streamflowsolutions.streamflow.media.kurento.messages.out.RejectionMessage;
import lombok.extern.slf4j.Slf4j;
import org.kurento.client.KurentoClient;
import org.kurento.client.MediaPipeline;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

@Slf4j
@Component
public class OneToManyKurento {

    private final Signaling messagingService;
    private final KurentoClient kurento;
    private final Map<String, KurentoUserSession> viewers = new ConcurrentHashMap<>();

    private MediaPipeline pipeline;
    private KurentoUserSession streamerSession;

    @Autowired
    public OneToManyKurento(Signaling messagingService, KurentoClient kurento) {
        this.messagingService = messagingService;
        this.kurento = kurento;
    }

    public void signalingConnectionClosed(String sessionId) {
        stop(sessionId);
    }

    public synchronized void startStreaming(String sessionId, StartStreamMessage message) {
        if (streamerSession == null) {
            createStreamer(sessionId, message);
        } else {
            sendStreamerAlreadyExistsMessage(sessionId);
        }
    }

    public synchronized void startWatch(String sessionId, StartWatchMessage message) {
        if (streamerSession == null) {
            sendNoSenderMessage(sessionId);
            return;
        }
        if (viewers.containsKey(sessionId)) {
            sendAlreadyViewerMessage(sessionId);
            return;
        }
        createViewer(sessionId, message);
    }

    public synchronized void stop(String sessionId) {
        if (streamerSession != null && isStreamerSession(sessionId)) {
            stopStreamer();
        }
        if (viewers.containsKey(sessionId)) {
            stopViewer(sessionId);
        }
    }

    public void handleIceCandidate(String sessionId, IceCandidateMessage msg) {
        if (streamerSession != null && isStreamerSession(sessionId)) {
            streamerSession.addCandidate(msg.getCandidate());
            return;
        }
        if (viewers.containsKey(sessionId)) {
            KurentoUserSession viewerSession = viewers.get(sessionId);
            viewerSession.addCandidate(msg.getCandidate());
        }
    }

    private void sendStreamerAlreadyExistsMessage(String sessionId) {
        RejectionMessage response = new RejectionMessage("Another user is currently acting as sender. Try again later ...");
        messagingService.sendMessage(sessionId, response);
    }

    private void createStreamer(String sessionId, StartStreamMessage message) {
        pipeline = kurento.createMediaPipeline();
        streamerSession = newUserSession(sessionId);
        String sdpOffer = message.getSdpOffer();
        streamerSession.processOffer(sdpOffer);
    }

    private void sendNoSenderMessage(String sessionId) {
        RejectionMessage response = new RejectionMessage("No active sender now. Become sender or . Try again later ...");
        messagingService.sendMessage(sessionId, response);
    }

    private void sendAlreadyViewerMessage(String sessionId) {
        RejectionMessage response = new RejectionMessage("You are already viewing in this session. "
                + "Use a different browser to add additional viewers.");
        messagingService.sendMessage(sessionId, response);
    }

    private void createViewer(String sessionId, StartWatchMessage message) {
        KurentoUserSession viewer = newUserSession(sessionId);
        streamerSession.connect(viewer);
        viewers.put(sessionId, viewer);
        String sdpOffer = message.getSdpOffer();
        viewer.processOffer(sdpOffer);
    }

    private void stopStreamer() {
        stopAllViewers();
        releaseMediaPipeline();
        streamerSession = null;
    }

    private void releaseMediaPipeline() {
        if (pipeline != null) {
            pipeline.release();
        }
        pipeline = null;
    }

    private void stopViewer(String sessionId) {
        if (viewers.containsKey(sessionId)) {
            KurentoUserSession userSession = viewers.get(sessionId);
            userSession.release();
            viewers.remove(sessionId);
        }
    }

    private void stopAllViewers() {
        for (KurentoUserSession viewer : viewers.values()) {
            StopCommunicationMessage stopCommunication = new StopCommunicationMessage();
            viewer.sendMessage(stopCommunication);
        }
    }

    private boolean isStreamerSession(String sessionId) {
        return streamerSession.getSessionId().equals(sessionId);
    }

    private KurentoUserSession newUserSession(String sessionId) {
        return new KurentoUserSession(sessionId, messagingService, pipeline);
    }
}
