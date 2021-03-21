package com.streamflowsolutions.streamflow.media.kurento.messages.in;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class StartWatchMessage {
    String sdpOffer;
}
