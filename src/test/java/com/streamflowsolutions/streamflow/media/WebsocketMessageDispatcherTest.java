package com.streamflowsolutions.streamflow.media;

import com.streamflowsolutions.streamflow.media.lib.MessageConverter;
import com.streamflowsolutions.streamflow.media.lib.WebsocketMessageDispatcher;
import com.streamflowsolutions.streamflow.media.lib.WebsocketMessageHandler;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.SneakyThrows;
import org.junit.jupiter.api.Test;
import org.springframework.web.socket.TextMessage;
import org.springframework.web.socket.WebSocketSession;

import static org.mockito.Mockito.*;

class WebsocketMessageDispatcherTest {

    @Data
    @AllArgsConstructor
    @NoArgsConstructor
    private static class TestMessage {
        private String first;
        private int second;
    }

    @Test
    @SneakyThrows
    void shouldDispatchMessageToHandler() {
        MessageConverter mockedConverter = mock(MessageConverter.class);
        WebsocketMessageHandler<TestMessage> mockedHandler = mock(WebsocketMessageHandler.class);

        WebsocketMessageDispatcher dispatcher = new WebsocketMessageDispatcher(mockedConverter);
        dispatcher.addHandler(TestMessage.class, mockedHandler);

        WebSocketSession mockedSession = mock(WebSocketSession.class);
        TestMessage messageToDispatch = new TestMessage("msg", 1);

        when(mockedConverter.deserialize(anyString())).thenReturn(messageToDispatch);

        dispatcher.dispatch(new TextMessage(""), mockedSession);

        verify(mockedHandler, times(1)).handleMessage(messageToDispatch, mockedSession);
    }

}
