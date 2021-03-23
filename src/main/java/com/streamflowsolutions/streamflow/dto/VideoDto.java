package com.streamflowsolutions.streamflow.dto;

import javax.validation.constraints.NotBlank;

import com.streamflowsolutions.streamflow.entity.User;
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
public class VideoDto {

    private long id;

    @NotBlank(message = "Property 'title' cannot be empty")
    private String title;

    @NotBlank(message = "Property 'date_of_publication' cannot be empty")
    private String date_of_publication;

    @NotBlank(message = "Property 'preview_src' cannot be empty")
    private String preview_src;

    private String description;

    @NotBlank(message = "Property 'author' cannot be empty")
    private User author;

    @NotBlank(message = "Property 'author' cannot be empty")
    private String video_src;

    //private List<Vote> votes;

    //private List<View> views;
}
