package com.streamflowsolutions.streamflow.exception.exceptions;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.springframework.test.context.junit.jupiter.SpringExtension;

@ExtendWith(SpringExtension.class)
public class NullEntityReferenceExceptionTest {
    
    @Test
    void isValidMessage() {
        final String expected = "Entity cannot be 'null'";
        final String actual = new NullEntityReferenceException("Entity")
                .getMessage();
        Assertions.assertEquals(expected, actual);
    }
    
}
