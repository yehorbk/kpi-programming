package com.streamflowsolutions.streamflow.media.lib;

import com.streamflowsolutions.streamflow.media.lib.exception.WebsocketSessionAlreadyExists;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.web.socket.TextMessage;
import org.springframework.web.socket.WebSocketSession;

import java.io.IOException;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.*;

class MessagingServiceTest {

    private MessagingService messagingService;
    private MessageConverter mockedConverter;

    @BeforeEach
    public void init() {
        mockedConverter = mock(MessageConverter.class);
        messagingService = new MessagingService(mockedConverter);
    }

    @Test
    void shouldSendMessageThroughWebsocket() throws IOException {
        String sessionId = "1";
        WebSocketSession session = mockedSession(sessionId);

        TestMessage testMessage = new TestMessage("text", 1);

        String serializedTestMessage = "serializedTestMessage";
        when(mockedConverter.serialize(testMessage)).thenReturn(serializedTestMessage);

        messagingService.addWebSocketSession(session);
        messagingService.sendMessage(sessionId, testMessage);

        verify(session, times(1)).sendMessage(new TextMessage(serializedTestMessage));
    }

    @Test
    void shouldThrowErrorWhenAddDuplicatedWebsocketSession() {
        WebSocketSession session1 = mockedSession("1");
        WebSocketSession sessionDuplicate = mockedSession("1");

        messagingService.addWebSocketSession(session1);
        assertThrows(WebsocketSessionAlreadyExists.class, () -> messagingService.addWebSocketSession(sessionDuplicate));
    }

    @Test
    void shouldDoesNotThrowErrorWhenAddUniqWebsocketSession() {
        WebSocketSession session1 = mockedSession("1");
        WebSocketSession session2 = mockedSession("2");

        messagingService.addWebSocketSession(session1);
        assertDoesNotThrow(() -> messagingService.addWebSocketSession(session2));
    }

    private WebSocketSession mockedSession(String sessionId) {
        WebSocketSession session = mock(WebSocketSession.class);
        when(session.getId()).thenReturn(sessionId);
        return session;
    }


}
