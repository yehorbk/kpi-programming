package com.streamflowsolutions.streamflow.media.config;

import org.kurento.client.KurentoClient;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class KurentoConfiguration {

    @Bean
    public KurentoClient kurentoClient() {
        return KurentoClient.create();
    }
}
