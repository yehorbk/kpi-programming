package com.streamflowsolutions.streamflow.media.lib;

import com.streamflowsolutions.streamflow.media.lib.exception.NoSuchSerializedMessageType;
import lombok.SneakyThrows;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class MessageConverterTest {

    private MessageConverter messageConverter;

    @BeforeEach
    void init() {
        messageConverter = new MessageConverter();
    }

    @Test
    @SneakyThrows
    void shouldSerializeMessage() {
       TestMessage testMessage = new TestMessage("text", 1);
        String expected = "{\"type\":\"TestMessage\",\"content\":{\"first\":\"text\",\"second\":1}}";

        String actual = messageConverter.serialize(testMessage);
        assertEquals(expected, actual);
    }

    @Test
    @SneakyThrows
    void shouldDeserializeMessage() {
        String serializedMessage = "{\"type\":\"TestMessage\",\"content\":{\"first\":\"text\",\"second\":1}}";
        TestMessage expected = new TestMessage("text", 1);

        messageConverter.addMessageType(TestMessage.class);
        Object actual = messageConverter.deserialize(serializedMessage);

        assertEquals(expected, actual);
    }

    @Test
    void shouldThrowErrorWhenNoSuchMessageType() {
        String serializedMessage = "{\"type\":\"TestMessage\",\"content\":{\"first\":\"text\",\"second\":1}}";
        Assertions.assertThrows(NoSuchSerializedMessageType.class, () -> messageConverter.deserialize(serializedMessage));
    }
}
