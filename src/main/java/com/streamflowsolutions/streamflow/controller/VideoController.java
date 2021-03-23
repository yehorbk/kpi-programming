package com.streamflowsolutions.streamflow.controller;

import com.streamflowsolutions.streamflow.dto.VideoDto;
import com.streamflowsolutions.streamflow.service.VideoService;
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
public class VideoController {

    private final VideoService videoService;

    private final ModelMapper modelMapper;

    public VideoController(
            VideoService videoService,
            ModelMapper modelMapper) {
        this.videoService = videoService;
        this.modelMapper = modelMapper;
    }

    @RequestMapping(value = "/videos", method = RequestMethod.POST)
    public ResponseEntity<VideoDto> createVideo(@RequestBody VideoDto videoDto) {
        VideoDto result = this.modelMapper.map(
                this.videoService.create(videoDto),
                VideoDto.class
        );
        return ResponseEntity
                .status(HttpStatus.OK)
                .body(result);
    }

    @RequestMapping(value = "/videos/{id}", method = RequestMethod.GET)
    public ResponseEntity<VideoDto> readVideo(@NotBlank @PathVariable long id) {
        VideoDto result = this.modelMapper.map(
                this.videoService.readById(id),
                VideoDto.class
        );
        return ResponseEntity
                .status(HttpStatus.OK)
                .body(result);
    }

    @RequestMapping(value = "/videos", method = RequestMethod.PUT)
    public ResponseEntity<VideoDto> updateVideo(@RequestBody VideoDto videoDto) {
        VideoDto result = this.modelMapper.map(
                this.videoService.update(videoDto),
                VideoDto.class
        );
        return ResponseEntity
                .status(HttpStatus.OK)
                .body(result);
    }

    @RequestMapping(value = "/videos/{id}", method = RequestMethod.DELETE)
    public ResponseEntity<Void> deleteVideo(@NotBlank @PathVariable long id) {
        this.videoService.delete(id);
        return ResponseEntity.status(HttpStatus.OK).build();
    }

    @RequestMapping(value = "/videos", method = RequestMethod.GET)
    public ResponseEntity<List<VideoDto>> readAll() {
        List<VideoDto> result = this.videoService.getAll().stream()
                .map(video -> this.modelMapper.map(video, VideoDto.class))
                .collect(Collectors.toList());
        return ResponseEntity
                .status(HttpStatus.OK)
                .body(result);
    }

}