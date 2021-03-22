package com.streamflowsolutions.streamflow.media.lib;

import com.streamflowsolutions.streamflow.media.lib.exception.WebsocketMessageHandlerAlreadyExists;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.web.socket.TextMessage;
import org.springframework.web.socket.WebSocketSession;

import java.io.IOException;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

@Component
public class WebsocketMessageDispatcher {

    private final Map<Class<?>, WebsocketMessageHandler<?>> handlers = new ConcurrentHashMap<>();
    private final MessageConverter converter;

    @Autowired
    public WebsocketMessageDispatcher(MessageConverter converter) {
        this.converter = converter;
    }

    public void dispatch(TextMessage message, WebSocketSession session) throws IOException {
        String payload = message.getPayload();
        Object deserializedMessage = converter.deserialize(payload);
        Class<?> type = deserializedMessage.getClass();
        WebsocketMessageHandler<Object> handler = (WebsocketMessageHandler<Object>) handlers.get(type);
        handler.handleMessage(deserializedMessage, session);
    }

    public <T> WebsocketMessageDispatcher addHandler(Class<T> type, WebsocketMessageHandler<T> handler) {
        if (handlers.containsKey(type)) {
            throw new WebsocketMessageHandlerAlreadyExists(type);
        }
        handlers.put(type, handler);
        return this;
    }
}
