package com.streamflowsolutions.streamflow.dto;

import java.time.LocalDate;
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
    
    @NotBlank(message = "Property 'tag' cannot be empty")
    private String tag;
    
    @NotBlank(message = "Property 'name' cannot be empty")
    private String name;
    
    private String bio;
    
    private String gender;
    
    private String nationality;
    
    private LocalDate dateOfBirth;
    
    private LocalDate dateOfCreation;
    
    private String avatarSrc;
    
    /*
        - subscriptions: [User] // OneToMany
        - subscribers: [User] // ManyToOne
        - history: [Video] // OneToMany
        - videos: [Video] // OneToMany
        - playlists: [Playlist] // OneToMany
    */
    
}
