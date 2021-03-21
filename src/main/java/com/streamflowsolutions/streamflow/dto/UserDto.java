package com.streamflowsolutions.streamflow.dto;

import javax.validation.constraints.NotBlank;
import lombok.AllArgsConstructor;
import lombok.EqualsAndHashCode;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

@NoArgsConstructor
@AllArgsConstructor
@Getter
@Setter
@EqualsAndHashCode(exclude = { "password" })
@ToString(exclude = { "password" })
public class UserDto {
    
    private long id;
    
    @NotBlank(message = "Propery 'email' cannot be empty")
    private String email;
    
    @NotBlank(message = "Property 'password' cannot be empty")
    private String password;
    
    /*
        TODO: implement more fields
    */
    
}
