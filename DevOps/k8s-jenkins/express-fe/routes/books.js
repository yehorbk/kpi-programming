/**
* @swagger
*  components:
*    schemas:
*      Book:
*        type: object
*        required:
*          - title
*          - author
*          - finished
*        properties:
*          id:
*            type: integer
*            description: The auto-generated id of the book.
*          title:
*            type: string
*            description: The title of your book.
*          author:
*            type: string
*            description: Who wrote the book?
*          finished:
*            type: boolean
*            description: Have you finished reading it?
*          createdAt:
*            type: string
*            format: date
*            description: The date of the record creation.
*        example:
*           title: The Pragmatic Programmer
*           author: Andy Hunt / Dave Thomas
*           finished: true
*/

/**
* @swagger
* tags:
*   name: Books
*   description: API to manage your books.
*/

const express = require("express");
const axios = require("axios").default;
const router = express.Router();

const baseUrl = process.env.BASE_URL || "http://localhost:8080/api";

const parser = ({ id, title, author, finished, createdAt }) => {
	return { id, title, author, finished, createdAt }
};

/**
* @swagger
*
* /books:
*   get:
*     summary: Lists all the books
*     tags: [Books]
*     responses:
*       "200":
*         description: The list of books.
*         content:
*           application/json:
*             schema:
*               type: array
*               items:
*                 $ref: '#/components/schemas/Book'
*/
router.get("/", async (req, res) => {
	try {
		const { data } = await axios.get(`${baseUrl}/books`);
		const books = data["_embedded"].books.map(parser);
		res.status(200).json(books);
	} catch (error) {
		res.status(400).json({ reason: "API Error" });
	}
});

/**
* @swagger
*
* /books/{id}:
*   get:
*     summary: Gets a book by id
*     tags: [Books]
*     parameters:
*       - in: path
*         name: id
*         schema:
*           type: integer
*         required: true
*         description: The book id
*     responses:
*       "200":
*         description: The list of books.
*         content:
*           application/json:
*             schema:
*               $ref: '#/components/schemas/Book'
*       "404":
*         description: Book not found.
*/
router.get("/:id", async (req, res) => {
	try {
		const { data } = await axios.get(`${baseUrl}/books/${req.params.id}`);
		data ? res.status(200).json(parser(data)) : res.sendStatus(404);
	} catch (error) {
		if (error.response.status === 404) {
			res.sendStatus(404);
		} else {
			res.status(400).json({ reason: "API Error" });
		}
	}
});

/**
* @swagger
*
* /books:
*   post:
*     summary: Creates a new book
*     tags: [Books]
*     requestBody:
*       required: true
*       content:
*         application/json:
*           schema:
*             $ref: '#/components/schemas/Book'
*     responses:
*       "201":
*         description: The created book.
*         content:
*           application/json:
*             schema:
*               $ref: '#/components/schemas/Book'
*/
router.post("/", async (req, res) => {
	const { title, author, finished } = req.body;

	let book = {
		title: title,
		author: author,
		finished: finished !== undefined ? finished : false,
	};

	try {
		const { data } = await axios.post(`${baseUrl}/books`, book);
		data ? res.status(201).json(parser(data)) : res.status(400).json({ reason: "API Error" });
	} catch (error) {
		res.status(400).json({ reason: "API Error" });
	}
});

/**
* @swagger
* /books/{id}:
*   put:
*     summary: Updates a book
*     tags: [Books]
*     parameters:
*       - in: path
*         name: id
*         schema:
*           type: integer
*         required: true
*         description: The book id
*     requestBody:
*       required: true
*       content:
*         application/json:
*           schema:
*             $ref: '#/components/schemas/Book'
*     responses:
*       "200":
*         description: Update was successful.
*       "404":
*         description: Book not found.
*/
router.put("/:id", async (req, res) => {
	try {
		const { data } = await axios.get(`${baseUrl}/books/${req.params.id}`);
		if (data) {
			const { title, author, finished } = req.body;
			const book = parser(data);

			let updated = {
				id: book.id,
				title: title !== undefined ? title : book.title,
				author: author !== undefined ? author : book.author,
				finished: finished !== undefined ? finished : book.finished,
				createdAt: book.createdAt,
			};
			const response = await axios.put(`${baseUrl}/books/${book.id}`, updated);
			response.data ? res.status(200).json(parser(response.data)) : res.status(400).json({ reason: "API Error" });
		} else {
			res.sendStatus(404);
		}
	} catch (error) {
		if (error.response.status === 404) {
			res.sendStatus(404);
		} else {
			res.status(400).json({ reason: "API Error" });
		}
	}
});

/**
* @swagger
*
* /books/{id}:
*   delete:
*     summary: Deletes a book by id
*     tags: [Books]
*     parameters:
*       - in: path
*         name: id
*         schema:
*           type: integer
*         required: true
*         description: The book id
*     responses:
*      "204":
*        description: Delete was successful.
*      "404":
*        description: Book not found.
*/
router.delete("/:id", async (req, res) => {
	try {
		const response = await axios.delete(`${baseUrl}/books/${req.params.id}`);
		res.sendStatus(204);
	} catch (error) {
		res.status(400).json({ reason: "API Error" });
	}
});

module.exports = router;
