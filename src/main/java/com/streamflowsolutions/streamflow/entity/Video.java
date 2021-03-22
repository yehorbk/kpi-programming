package com.streamflowsolutions.streamflow.entity;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

@Entity
@Table(name = "videos")
@NoArgsConstructor
@AllArgsConstructor
@Getter
@Setter
public class Video {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private long id;

    @Column(name = "title", nullable = false, unique = true)
    private String title;

    @Column(name = "description")
    private String description;

    @Column(name = "date_of_publication", nullable = false)
    private String date_of_publication;

    @Column(name = "author", nullable = false)
    private User author;

    @Column(name = "preview_src", nullable = false)
    private String preview_src;

    //@Column(name = "video_src", nullable = false, unique = true)
    //private String video_src;

    //@Column(name = "votes")
    //private List<Vote> votes;
}