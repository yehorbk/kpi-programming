module.exports = {
    definition: {
        openapi: "3.0.0",
        info: {
            title: "Express API",
            version: "0.1.0",
            description:
                "This is a simple CRUD API application",
            license: {
                name: "MIT",
                url: "https://spdx.org/licenses/MIT.html",
            },
            contact: {
                name: "Dmytro Minochkin",
                url: "https://example.com",
                email: "info@email.com",
            },
        },
    },
    apis: ["./routes/books.js"],
};