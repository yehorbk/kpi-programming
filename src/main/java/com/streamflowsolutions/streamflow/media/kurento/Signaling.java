package com.streamflowsolutions.streamflow.media.kurento;

public interface Signaling {
    void sendMessage(String sessionId, Object message);
}
