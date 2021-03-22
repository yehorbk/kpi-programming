package com.streamflowsolutions.streamflow.media.lib;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;
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
 *
 * To be converted object must has empty constructor and getters/setters
 * for all fields that supposed to be serialized/deserialized
 */

@Component
public class MessageConverter {

    private final Map<String, Class<?>> types = new ConcurrentHashMap<>();

    private final ObjectMapper mapper = new ObjectMapper()
            .configure(SerializationFeature.FAIL_ON_EMPTY_BEANS, false);

    public MessageConverter addMessageType(Class<?> type) {
        types.putIfAbsent(type.getSimpleName(), type);
        return this;
    }

    public String serialize(Object obj) throws JsonProcessingException {
        JsonNode serializedContent = serializeMessageContent(obj);
        String serializedType = serializeMessageType(obj.getClass());
        JsonMessage jsonMessage = new JsonMessage(serializedType, serializedContent);
        return mapper.writeValueAsString(jsonMessage);
    }

    public Object deserialize(String msg) throws IOException {
        JsonMessage jsonMessage = mapper.readValue(msg, JsonMessage.class);
        Class<?> type = deserializeMessageType(jsonMessage);
        return deserializeMessageContent(jsonMessage, type);
    }

    private String serializeMessageType(Class<?> type) {
        String serializedType = type.getSimpleName();
        types.putIfAbsent(serializedType, type);
        return serializedType;
    }

    private Class<?> deserializeMessageType(JsonMessage message) {
        return types.get(message.getType());
    }

    private JsonNode serializeMessageContent(Object obj) {
        return mapper.convertValue(obj, JsonNode.class);
    }

    private Object deserializeMessageContent(JsonMessage msg, Class<?> type) throws IOException {
        return mapper.readValue(msg.getContent().traverse(), type);
    }
}
