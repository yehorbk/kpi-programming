package com.streamflowsolutions.streamflow.media.kurento.messages.bi;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class StopCommunicationMessage {
    private String reason;
}
