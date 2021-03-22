package com.streamflowsolutions.streamflow.media.kurento;

import java.io.IOException;

public interface Signaling {
    void sendMessage(String sessionId, Object message) throws IOException;
}
