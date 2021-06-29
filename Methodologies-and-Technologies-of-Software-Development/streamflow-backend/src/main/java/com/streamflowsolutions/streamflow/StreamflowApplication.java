package com.streamflowsolutions.streamflow;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.security.servlet.SecurityAutoConfiguration;
import org.springframework.boot.web.servlet.support.SpringBootServletInitializer;
import org.springframework.web.socket.config.annotation.EnableWebSocket;

@SpringBootApplication(exclude = { SecurityAutoConfiguration.class })
@EnableWebSocket
public class StreamflowApplication extends SpringBootServletInitializer {

    public static void main(String[] args) {
	SpringApplication.run(StreamflowApplication.class, args);
    }

}
