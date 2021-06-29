package com.streamflowsolutions.streamflow.media.lib.exception;

public class WebsocketMessageHandlerAlreadyExists extends RuntimeException {

    public WebsocketMessageHandlerAlreadyExists(Class<?> messageType) {
        super("Websocket message handler for this message type already exists: " + messageType.getSimpleName());
    }
}
