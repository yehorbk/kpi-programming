package com.streamflowsolutions.streamflow.media.kurento.messages.bi;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.kurento.client.IceCandidate;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class IceCandidateMessage {
    private IceCandidate candidate;
}
