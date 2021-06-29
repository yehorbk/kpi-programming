package com.streamflowsolutions.streamflow.exception.exceptions;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.springframework.test.context.junit.jupiter.SpringExtension;

@ExtendWith(SpringExtension.class)
public class StreamflowEntityNotFoundExceptionTest {
    
    @Test
    void isValidMessage() {
        final String expected = "Entity with field=value not found";
        final String actual = new StreamflowEntityNotFoundException(
                "Entity", "field", "value").getMessage();
        Assertions.assertEquals(expected, actual);
    }
    
}
