package com.streamflowsolutions.streamflow;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.autoconfigure.security.servlet.SecurityAutoConfiguration;

@SpringBootApplication(exclude = { SecurityAutoConfiguration.class })
public class StreamflowApplication {

    public static void main(String[] args) {
	SpringApplication.run(StreamflowApplication.class, args);
    }

}
