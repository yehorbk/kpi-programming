package com.streamflowsolutions.streamflow.media.lib;

import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;
import com.streamflowsolutions.streamflow.media.lib.exception.NoSuchSerializedMessageType;
import lombok.SneakyThrows;
import org.springframework.stereotype.Component;

import java.io.IOException;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;


/**
 * Message structure:
 * {
 * type: [String],
 * content: [Object]
 * }
 * <p>
 * To be converted object must has empty constructor and getters/setters
 * for all fields that supposed to be serialized/deserialized
 */

@Component
public class MessageConverter {

    private final Map<String, Class<?>> types = new ConcurrentHashMap<>();

    private final ObjectMapper mapper = new ObjectMapper()
            .configure(SerializationFeature.FAIL_ON_EMPTY_BEANS, false);

    public void addMessageType(Class<?> type) {
        types.putIfAbsent(type.getSimpleName(), type);
    }

    @SneakyThrows
    public String serialize(Object obj) {
        Class<?> type = obj.getClass();
        addMessageType(type);
        JsonNode serializedContent = serializeMessageContent(obj);
        String serializedType = serializeMessageType(type);
        JsonMessage jsonMessage = new JsonMessage(serializedType, serializedContent);
        return mapper.writeValueAsString(jsonMessage);
    }

    @SneakyThrows
    public Object deserialize(String msg) {
        JsonMessage jsonMessage = mapper.readValue(msg, JsonMessage.class);
        Class<?> type = deserializeMessageType(jsonMessage);
        return deserializeMessageContent(jsonMessage, type);
    }

    private String serializeMessageType(Class<?> type) {
        String serializedType = type.getSimpleName();
        types.putIfAbsent(serializedType, type);
        return serializedType;
    }

    private Class<?> deserializeMessageType(JsonMessage message) throws NoSuchSerializedMessageType {
        if (!types.containsKey(message.getType())) {
            throw new NoSuchSerializedMessageType(message);
        }
        return types.get(message.getType());
    }

    private JsonNode serializeMessageContent(Object obj) {
        return mapper.convertValue(obj, JsonNode.class);
    }

    private Object deserializeMessageContent(JsonMessage msg, Class<?> type) throws IOException {
        return mapper.readValue(msg.getContent().traverse(), type);
    }
}
