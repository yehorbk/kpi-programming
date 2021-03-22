package com.streamflowsolutions.streamflow.exception.exceptions;

public class NullEntityReferenceException extends NullPointerException {

    public NullEntityReferenceException(String entity) {
        super(String.format("%s cannot be 'null'", entity));
    }
    
}
