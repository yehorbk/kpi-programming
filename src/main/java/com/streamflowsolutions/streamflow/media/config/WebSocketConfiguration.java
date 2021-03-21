package com.streamflowsolutions.streamflow.media.config;

import com.streamflowsolutions.streamflow.media.KurentoWebsocketHandler;
import com.streamflowsolutions.streamflow.media.lib.MessageConverter;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.socket.config.annotation.WebSocketConfigurer;
import org.springframework.web.socket.config.annotation.WebSocketHandlerRegistry;
import org.springframework.web.socket.server.standard.ServletServerContainerFactoryBean;

@Configuration
public class WebSocketConfiguration implements WebSocketConfigurer {

    private final KurentoWebsocketHandler kurento;

    @Bean
    public ServletServerContainerFactoryBean createServletServerContainerFactoryBean() {
        ServletServerContainerFactoryBean container = new ServletServerContainerFactoryBean();
        container.setMaxTextMessageBufferSize(32768);
        return container;
    }

    @Autowired
    public WebSocketConfiguration(KurentoWebsocketHandler kurento) {
        this.kurento = kurento;
    }

    @Override
    public void registerWebSocketHandlers(WebSocketHandlerRegistry registry) {
        registry.addHandler(kurento, "/kurento")
                .setAllowedOrigins("*");
    }
}
