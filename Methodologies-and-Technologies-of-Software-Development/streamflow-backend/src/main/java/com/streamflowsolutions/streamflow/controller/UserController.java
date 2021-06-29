package com.streamflowsolutions.streamflow.controller;

import com.streamflowsolutions.streamflow.dto.UserDto;
import com.streamflowsolutions.streamflow.service.UserService;
import java.util.List;
import java.util.stream.Collectors;
import javax.validation.constraints.NotBlank;
import org.modelmapper.ModelMapper;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/rest")
public class UserController {

    private final UserService userService;
    
    private final ModelMapper modelMapper;

    public UserController(
            UserService userService,
            ModelMapper modelMapper) {
        this.userService = userService;
        this.modelMapper = modelMapper;
    }
    
    @RequestMapping(value = "/users", method = RequestMethod.POST)
    public ResponseEntity<UserDto> createUser(@RequestBody UserDto userDto) {
        UserDto result = this.modelMapper.map(
                this.userService.create(userDto), UserDto.class);
        return ResponseEntity
                .status(HttpStatus.OK)
                .body(result);
    }
    
    @RequestMapping(value = "/users/{id}", method = RequestMethod.GET)
    public ResponseEntity<UserDto> readUser(@NotBlank @PathVariable long id) {
        UserDto result = this.modelMapper.map(
                this.userService.readById(id), UserDto.class);
        return ResponseEntity
                .status(HttpStatus.OK)
                .body(result);
    }
    
    @RequestMapping(value = "/users", method = RequestMethod.PUT)
    public ResponseEntity<UserDto> updateUser(@RequestBody UserDto userDto) {
        UserDto result = this.modelMapper.map(
                this.userService.update(userDto), UserDto.class);
        return ResponseEntity
                .status(HttpStatus.OK)
                .body(result);
    }
    
    @RequestMapping(value = "/users/{id}", method = RequestMethod.DELETE)
    public ResponseEntity<Void> deleteUser(@NotBlank @PathVariable long id) {
        this.userService.delete(id);
        return ResponseEntity.status(HttpStatus.OK).build();
    }
    
    @RequestMapping(value = "/users", method = RequestMethod.GET)
    public ResponseEntity<List<UserDto>> readAll() {
        List<UserDto> result = this.userService.getAll().stream()
                .map(user -> this.modelMapper.map(user, UserDto.class))
                .collect(Collectors.toList());
        return ResponseEntity
                .status(HttpStatus.OK)
                .body(result);
    }
    
}
