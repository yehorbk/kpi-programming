package com.streamflowsolutions.streamflow.media.lib.exception;

import org.springframework.web.socket.WebSocketSession;

public class WebsocketSessionAlreadyExists extends RuntimeException {
    public WebsocketSessionAlreadyExists(WebSocketSession session) {
        super("Websocket session with this id already exists: " + session.getId());
    }
}
