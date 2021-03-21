package com.streamflowsolutions.streamflow.media.kurento;

import com.streamflowsolutions.streamflow.media.kurento.messages.bi.IceCandidateMessage;
import com.streamflowsolutions.streamflow.media.kurento.messages.out.SdpAnswerMessage;
import org.kurento.client.IceCandidate;
import org.kurento.client.IceCandidateFoundEvent;
import org.kurento.client.MediaPipeline;
import org.kurento.client.WebRtcEndpoint;

public class KurentoUserSession {

    private final String sessionId;
    private final Signaling signaling;
    private final WebRtcEndpoint endpoint;

    public KurentoUserSession(String sessionId, Signaling signaling, MediaPipeline pipeline) {
        this.sessionId = sessionId;
        this.signaling = signaling;
        endpoint = new WebRtcEndpoint.Builder(pipeline).build();
        endpoint.addIceCandidateFoundListener(this::iceCandidateFoundListener);
    }

    public void addCandidate(IceCandidate candidate) {
        endpoint.addIceCandidate(candidate);
    }

    public void sendMessage(Object message) {
        signaling.sendMessage(sessionId, message);
    }

    public void release() {
        endpoint.release();
    }

    public void connect(KurentoUserSession session) {
        this.endpoint.connect(session.endpoint);
    }

    public void processOffer(String sdpOffer) {
        String sdpAnswer = endpoint.processOffer(sdpOffer);
        SdpAnswerMessage response = new SdpAnswerMessage(sdpAnswer);
        sendMessage(response);
        endpoint.gatherCandidates();
    }

    private void iceCandidateFoundListener(IceCandidateFoundEvent event) {
        IceCandidateMessage iceCandidate = new IceCandidateMessage(event.getCandidate());
        sendMessage(iceCandidate);
    }

    public String getSessionId() {
        return sessionId;
    }
}
