package com.streamflowsolutions.streamflow.media.lib;

import com.streamflowsolutions.streamflow.media.lib.exception.WebsocketMessageHandlerAlreadyExists;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.SneakyThrows;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.web.socket.TextMessage;
import org.springframework.web.socket.WebSocketSession;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.*;

class WebsocketMessageDispatcherTest {

    private MessageConverter mockedConverter;
    private WebsocketMessageDispatcher dispatcher;

    @BeforeEach
    void init() {
        mockedConverter = mock(MessageConverter.class);
        dispatcher = new WebsocketMessageDispatcher(mockedConverter);
    }

    @Test
    @SneakyThrows
    void shouldDispatchMessageToHandler() {
        // given
        WebsocketMessageHandler<TestMessage> mockedHandler = mockMessageHandler();
        dispatcher.addHandler(TestMessage.class, mockedHandler);

        TestMessage messageToDispatch = new TestMessage("msg", 1);
        String serializedMessageToDispatch = "contains serialized 'message to dispatch'";
        TextMessage websocketMessage = new TextMessage(serializedMessageToDispatch);

        WebSocketSession mockedSession = mock(WebSocketSession.class);
        // when

        when(mockedConverter.deserialize(serializedMessageToDispatch)).thenReturn(messageToDispatch);
        dispatcher.dispatch(websocketMessage, mockedSession);

        // then
        verify(mockedHandler, times(1)).handleMessage(messageToDispatch, mockedSession);
    }

    @Test
    void shouldThrowErrorWhenAddDuplicatedMessageHandler() {
        WebsocketMessageHandler<TestMessage> mockedHandler1 = mockMessageHandler();
        WebsocketMessageHandler<TestMessage> mockedHandler2 = mockMessageHandler();

        dispatcher.addHandler(TestMessage.class, mockedHandler1);
        assertThrows(WebsocketMessageHandlerAlreadyExists.class, () -> {
            dispatcher.addHandler(TestMessage.class, mockedHandler2);
        });
    }

    @Test
    void shouldDoesNotThrowErrorWhenAddUniqMessageHandler() {
        WebsocketMessageHandler<TestMessage> mockedHandler1 = mockMessageHandler();
        WebsocketMessageHandler<TestMessage2> mockedHandler2 = mockMessageHandler();

        dispatcher.addHandler(TestMessage.class, mockedHandler1);
        assertDoesNotThrow(() -> {
            dispatcher.addHandler(TestMessage2.class, mockedHandler2);
        });
    }

    private <T> WebsocketMessageHandler<T> mockMessageHandler() {
        return mock(WebsocketMessageHandler.class);
    }

    @Data
    @AllArgsConstructor
    @NoArgsConstructor
    private static class TestMessage2 {
        private String first;
        private int second;
    }

}
