package com.streamflowsolutions.streamflow.media.lib;

import com.streamflowsolutions.streamflow.media.lib.exception.WebsocketSessionAlreadyExists;
import org.springframework.stereotype.Component;
import org.springframework.web.socket.TextMessage;
import org.springframework.web.socket.WebSocketSession;

import java.io.IOException;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

@Component
public class MessagingService  {

    private final Map<String, WebSocketSession> sessions = new ConcurrentHashMap<>();
    private final MessageConverter converter;

    public MessagingService(MessageConverter converter) {
        this.converter = converter;
    }

    public void addWebSocketSession(WebSocketSession session) {
        if (sessions.containsKey(session.getId())) {
            throw new WebsocketSessionAlreadyExists(session);
        }
        sessions.put(session.getId(), session);
    }

    public void removeWebSocketSession(WebSocketSession session) {
        sessions.put(session.getId(), session);
    }

    public void sendMessage(String sessionId, Object message) throws IOException {
        WebSocketSession session = sessions.get(sessionId);
        String json = converter.serialize(message);
        sendMessage(session, json);
    }

    private synchronized void sendMessage(WebSocketSession session, String json) throws IOException {
        session.sendMessage(new TextMessage(json));
    }
}
