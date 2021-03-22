package com.streamflowsolutions.streamflow.media.lib;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.streamflowsolutions.streamflow.media.kurento.Signaling;
import org.springframework.stereotype.Component;
import org.springframework.web.socket.TextMessage;
import org.springframework.web.socket.WebSocketSession;

import java.io.IOException;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

@Component
public class MessagingService implements Signaling {

    private final Map<String, WebSocketSession> sessions = new ConcurrentHashMap<>();
    private final MessageConverter converter;

    public MessagingService(MessageConverter converter) {
        this.converter = converter;
    }

    public void addWebSocketSession(WebSocketSession session) {
        sessions.put(session.getId(), session);
    }

    public void removeWebSocketSession(WebSocketSession session) {
        sessions.put(session.getId(), session);
    }

    @Override
    public void sendMessage(String sessionId, Object message) {
        WebSocketSession session = sessions.get(sessionId);
        String json = null;
        try {
            json = converter.serialize(message);
        } catch (JsonProcessingException e) {
            e.printStackTrace();
        }
        sendMessage(session, json);
    }

    private synchronized void sendMessage(WebSocketSession session, String json) {
        try {
            session.sendMessage(new TextMessage(json));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
