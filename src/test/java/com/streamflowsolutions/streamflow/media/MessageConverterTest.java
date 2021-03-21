package com.streamflowsolutions.streamflow.media;

import com.streamflowsolutions.streamflow.media.lib.MessageConverter;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.SneakyThrows;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class MessageConverterTest {

    @Data
    @AllArgsConstructor
    @NoArgsConstructor
    private static class TestMessage {
        private String first;
        private int second;
    }

    @Test
    @SneakyThrows
    void shouldSerializeMessage() {
        MessageConverter messageConverter = new MessageConverter();
        TestMessage testMessage = new TestMessage("text", 1);
        String expected = "{\"type\":\"TestMessage\",\"content\":{\"first\":\"text\",\"second\":1}}";

        String actual = messageConverter.serialize(testMessage);
        assertEquals(expected, actual);
    }

    @Test
    @SneakyThrows
    void shouldDeserializeMessage() {
        MessageConverter messageConverter = new MessageConverter()
                .addMessageType(TestMessage.class);
        String serializedMessage = "{\"type\":\"TestMessage\",\"content\":{\"first\":\"text\",\"second\":1}}";
        TestMessage expected = new TestMessage("text", 1);

        Object actual = messageConverter.deserialize(serializedMessage);
        assertEquals(expected, actual);
    }
}
