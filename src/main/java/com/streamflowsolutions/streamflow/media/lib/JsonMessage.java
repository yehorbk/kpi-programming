package com.streamflowsolutions.streamflow.media.lib;

import com.fasterxml.jackson.databind.JsonNode;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class JsonMessage {
    private String type;
    private JsonNode content;
}
