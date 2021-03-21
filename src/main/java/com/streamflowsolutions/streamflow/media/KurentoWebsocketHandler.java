package com.streamflowsolutions.streamflow.media;

import com.streamflowsolutions.streamflow.media.kurento.OneToManyKurento;
import com.streamflowsolutions.streamflow.media.kurento.messages.bi.IceCandidateMessage;
import com.streamflowsolutions.streamflow.media.kurento.messages.bi.StopCommunicationMessage;
import com.streamflowsolutions.streamflow.media.kurento.messages.in.StartStreamMessage;
import com.streamflowsolutions.streamflow.media.kurento.messages.in.StartWatchMessage;
import com.streamflowsolutions.streamflow.media.lib.MessagingService;
import com.streamflowsolutions.streamflow.media.lib.WebsocketMessageDispatcher;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Component;
import org.springframework.web.socket.CloseStatus;
import org.springframework.web.socket.TextMessage;
import org.springframework.web.socket.WebSocketSession;
import org.springframework.web.socket.handler.TextWebSocketHandler;

@Component
public class KurentoWebsocketHandler extends TextWebSocketHandler {

    private final WebsocketMessageDispatcher dispatcher;
    private final MessagingService messagingService;
    private final OneToManyKurento oneToManyKurento;

    @Autowired
    public KurentoWebsocketHandler(WebsocketMessageDispatcher dispatcher, MessagingService messagingService, OneToManyKurento oneToManyKurento) {
        this.dispatcher = dispatcher;
        this.messagingService = messagingService;
        this.oneToManyKurento = oneToManyKurento;
        dispatcher
                .addHandler(IceCandidateMessage.class, this::handleIceCandidate)
                .addHandler(StartWatchMessage.class, this::startWatch)
                .addHandler(StartStreamMessage.class, this::startStream)
                .addHandler(StopCommunicationMessage.class, this::stopCommunication);
    }

    private void handleIceCandidate(IceCandidateMessage message, WebSocketSession session) {
        oneToManyKurento.handleIceCandidate(session.getId(), message);
    }

    private void startWatch(StartWatchMessage message, WebSocketSession session) {
        oneToManyKurento.startWatch(session.getId(), message);
    }

    private void startStream(StartStreamMessage message, WebSocketSession session) {
        oneToManyKurento.startStreaming(session.getId(), message);
    }

    private void stopCommunication(StopCommunicationMessage message, WebSocketSession session) {
        oneToManyKurento.stop(session.getId());
    }

    @Override
    protected void handleTextMessage(@NonNull WebSocketSession session, @NonNull TextMessage message) throws Exception {
        dispatcher.dispatch(message, session);
    }

    @Override
    public void afterConnectionClosed(@NonNull WebSocketSession session, @NonNull CloseStatus status) {
        messagingService.removeWebSocketSession(session);
    }

    @Override
    public void afterConnectionEstablished(@NonNull WebSocketSession session) {
        messagingService.addWebSocketSession(session);
        oneToManyKurento.signalingConnectionClosed(session.getId());
    }
}
