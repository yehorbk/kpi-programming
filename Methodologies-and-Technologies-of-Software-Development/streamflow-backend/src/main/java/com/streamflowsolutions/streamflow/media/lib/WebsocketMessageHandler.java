package com.streamflowsolutions.streamflow.media.lib;

import org.springframework.web.socket.WebSocketSession;

@FunctionalInterface
public interface WebsocketMessageHandler<T> {
    void handleMessage(T message, WebSocketSession session);
}
