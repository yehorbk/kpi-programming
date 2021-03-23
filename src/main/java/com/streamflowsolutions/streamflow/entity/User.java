package com.streamflowsolutions.streamflow.entity;

import java.time.LocalDate;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import lombok.AllArgsConstructor;
import lombok.EqualsAndHashCode;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

@Entity
@Table(name = "users")
@NoArgsConstructor
@AllArgsConstructor
@Getter
@Setter
@EqualsAndHashCode(exclude = { "password" })
@ToString(exclude = { "password" })
public class User {
    
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private long id;
    
    @Column(name = "email", nullable = false, unique = true)
    private String email;
            
    @Column(name = "password", nullable = false)
    private String password;
   
    @Column(name = "tag", nullable = false, unique = true)
    private String tag;
    
    @Column(name = "name")
    private String name;
    
    @Column(name = "bio")
    private String bio;
    
    @Column(name = "gender")
    private String gender;
    
    @Column(name = "nationality")
    private String nationality;
    
    @Column(name = "date_of_birth")
    private LocalDate dateOfBirth;
    
    @Column(name = "date_of_creation")
    private LocalDate dateOfCreation;
    
    @Column(name = "avatar_src")
    private String avatarSrc;
    
    /*
        - subscriptions: [User] // OneToMany
        - subscribers: [User] // ManyToOne
        - history: [Video] // OneToMany
        - videos: [Video] // OneToMany
        - playlists: [Playlist] // OneToMany
    */
    
}
