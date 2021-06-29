package com.streamflowsolutions.streamflow.media.lib.exception;

import com.streamflowsolutions.streamflow.media.lib.JsonMessage;

public class NoSuchSerializedMessageType extends RuntimeException {
    public NoSuchSerializedMessageType(JsonMessage message) {
        super("Such message type wasn't add to MessageConverter before: " + message.getType());
    }
}
