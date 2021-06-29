package com.streamflowsolutions.streamflow.service.impl;

import com.streamflowsolutions.streamflow.dto.UserDto;
import com.streamflowsolutions.streamflow.entity.User;
import com.streamflowsolutions.streamflow.exception.exceptions.NullEntityReferenceException;
import com.streamflowsolutions.streamflow.exception.exceptions.StreamflowEntityNotFoundException;
import com.streamflowsolutions.streamflow.repository.UserRepository;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.Mockito;
import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.test.context.junit.jupiter.SpringExtension;

@ExtendWith(SpringExtension.class)
@SpringBootTest
public class UserServiceImplTest {
    
    @Autowired
    UserServiceImpl userService;
    
    @Autowired
    ModelMapper modelMapper;
    
    @MockBean
    UserRepository userRepository;
    
    private static final User USER = new User();
    private static final long USER_ID = 1;
    
    @BeforeEach
    public void setUp() {
        USER.setEmail("email@example.com");
        USER.setPassword("password");
        USER.setTag("@tag");
        USER.setName("Name");
        USER.setBio("Bio");
        USER.setGender("Gender");
        USER.setNationality("Nationality");
        USER.setDateOfBirth(LocalDate.MIN);
        Mockito.when(userRepository.findById(USER_ID))
                .thenReturn(Optional.of(USER));
        
    }
    
    @Test
    public void testCreateUser() {
        Mockito.when(this.userRepository.save(USER)).thenReturn(USER);
        UserDto actual = this.modelMapper.map(USER, UserDto.class);
        Assertions.assertEquals(USER, this.userService.create(actual));
    }
    
    @Test
    public void testCreateNullUser() {
        Assertions.assertThrows(NullEntityReferenceException.class,
                () -> this.userService.create(null));
    }
    
    @Test
    public void testReadByIdUser() {
        Assertions.assertEquals(USER, this.userService.readById(USER_ID));
    }
    
    @Test
    public void testUpdateUser() {
        Mockito.when(this.userRepository.save(USER)).thenReturn(USER);
        UserDto actual = this.modelMapper.map(USER, UserDto.class);
        actual.setId(USER_ID);
        Assertions.assertEquals(USER, this.userService.update(actual));
    }
    
    @Test
    public void testUpdateNullUser() {
        Assertions.assertThrows(NullEntityReferenceException.class,
                () -> this.userService.update(null));
    }
    
    @Test
    public void testUpdateNotExistUser() {
        UserDto actual = this.modelMapper.map(USER, UserDto.class);
        Assertions.assertThrows(StreamflowEntityNotFoundException.class,
                () -> this.userService.update(actual));
    }
    
    @Test
    public void testDeleteUser() {
        Mockito.doNothing().when(this.userRepository).delete(USER);
        this.userService.delete(USER_ID);
        Mockito.verify(this.userRepository, Mockito.times(1)).delete(USER);
    }
    
    @Test
    public void testDeleteNotExistUser() {
        Assertions.assertThrows(StreamflowEntityNotFoundException.class,
                () -> this.userService.delete(0));
    }
    
    @Test
    public void testGetAllUsers() {
        List<User> users = new ArrayList<>();
        users.add(USER);
        Mockito.when(this.userRepository.findAll()).thenReturn(users);
        Assertions.assertEquals(1, this.userService.getAll().size());
    }
    
    @Test
    public void testGetAllUsersWhenEmpty() {
        Assertions.assertEquals(0, this.userService.getAll().size());
    }
    
}
