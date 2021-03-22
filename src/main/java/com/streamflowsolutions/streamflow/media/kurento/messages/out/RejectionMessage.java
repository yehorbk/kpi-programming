package com.streamflowsolutions.streamflow.media.kurento.messages.out;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class RejectionMessage {
    private String reason;
}
