import org.jetbrains.kotlin.gradle.tasks.KotlinCompile

plugins {
    id("org.springframework.boot") version "2.7.2"
    id("io.spring.dependency-management") version "1.0.12.RELEASE"
    kotlin("jvm") version "1.6.21"
    kotlin("plugin.spring") version "1.6.21"
    kotlin("plugin.jpa") version "1.6.21"
    id("com.google.cloud.tools.jib") version "3.2.1"
}

group = "cloud.dmytrominochkin"
version = "0.0.1-SNAPSHOT"
java.sourceCompatibility = JavaVersion.VERSION_11

configurations {
    compileOnly {
        extendsFrom(configurations.annotationProcessor.get())
    }
}

repositories {
    mavenCentral()
}

dependencies {
    implementation("org.springframework.boot:spring-boot-starter-data-jpa")
    implementation("org.springframework.boot:spring-boot-starter-data-rest")
    implementation("org.springframework.data:spring-data-rest-hal-explorer")
    implementation("org.springframework.boot:spring-boot-starter-web")
    implementation("org.springframework.boot:spring-boot-starter-actuator")
    implementation("com.fasterxml.jackson.module:jackson-module-kotlin")
    implementation("org.jetbrains.kotlin:kotlin-reflect")
    implementation("org.jetbrains.kotlin:kotlin-stdlib-jdk8")
    developmentOnly("org.springframework.boot:spring-boot-devtools")
    runtimeOnly("mysql:mysql-connector-java")
    annotationProcessor("org.springframework.boot:spring-boot-configuration-processor")
    testImplementation("org.springframework.boot:spring-boot-starter-test")
}

tasks.withType<KotlinCompile> {
    kotlinOptions {
        freeCompilerArgs = listOf("-Xjsr305=strict")
        jvmTarget = "11"
    }
}

tasks.withType<Test> {
    useJUnitPlatform()
}

jib {
    to {
        image = "registry.gitlab.com/dmymi/k8s-simple-task/kotlin-be"
        tags = setOf("latest")
    }
    container {
        ports = listOf("8080")
        labels.putAll(
            mapOf(
                "maintainer" to "Dmytro Minochkin <dmytro.minochkin@gmail.com>",
                "org.opencontainers.image.title" to "kotlin-be",
                "org.opencontainers.image.description" to "An example CRUD service",
                "org.opencontainers.image.version" to "$version",
                "org.opencontainers.image.authors" to "Dmytro Minochkin <dmytro.minochkin@gmail.com>",
                "org.opencontainers.image.url" to "https://gitlab.com/DmyMi/k8s-simple-task"
            )
        )
    }
}