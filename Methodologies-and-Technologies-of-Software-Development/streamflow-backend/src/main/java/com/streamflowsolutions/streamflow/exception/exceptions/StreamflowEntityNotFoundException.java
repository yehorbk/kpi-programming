package com.streamflowsolutions.streamflow.exception.exceptions;

import javax.persistence.EntityNotFoundException;

public class StreamflowEntityNotFoundException extends EntityNotFoundException {
    
    public StreamflowEntityNotFoundException(
            String entity, String field, String value) {
        super(String.format("%s with %s=%s not found", entity, field, value));
    }
    
}
