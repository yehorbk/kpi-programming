package com.streamflowsolutions.streamflow.media.kurento.messages.out;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class SdpAnswerMessage {
    private String sdpAnswer;
}
