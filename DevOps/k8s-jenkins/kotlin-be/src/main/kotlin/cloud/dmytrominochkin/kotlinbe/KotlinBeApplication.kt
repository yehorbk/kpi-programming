package cloud.dmytrominochkin.kotlinbe

import org.springframework.boot.autoconfigure.SpringBootApplication
import org.springframework.boot.runApplication

@SpringBootApplication
class KotlinBeApplication

fun main(args: Array<String>) {
    runApplication<KotlinBeApplication>(*args)
}
