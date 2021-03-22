package com.streamflowsolutions.streamflow.media.kurento;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class SdpOffer {
    private String type;
    private String sdp;
}
