import { config } from "https://deno.land/std/dotenv/mod.ts";

// load environment variables from .env file
const ENV = await config();

// credentials to get client_credentials grant token 
const token_credentials = {
  client_id: ENV["CLIENT_ID"],
  client_secret: ENV["CLIENT_SECRET"],
  audience: ENV["AUDIENCE"],
  grant_type: "client_credentials",
};

const user_credentials = {
  email: ENV["EMAIL"],
  password: ENV["PASSWORD"],
  connection: "Username-Password-Authentication",
};

const getToken = async () => {
  // generate x-www-form-urlencoded body
  const form = Object.entries(token_credentials)
    .reduce<string[]>((array, entry) => {
      const encodedKey = encodeURIComponent(entry[0]);
      const encodedValue = encodeURIComponent(entry[1]);
      array.push(`${encodedKey}=${encodedValue}`);
      return array;
    }, [])
    .join("&");
  const data = await fetch(`https://${ENV["DOMAIN"]}/oauth/token`, {
    method: "POST",
    headers: {
      "Content-Type": "application/x-www-form-urlencoded",
    },
    body: form,
  });
  const { token_type, access_token } = await data.json();
  return `${token_type} ${access_token}`;
};

const createUser = async (token) => {
  const data = await fetch(`${ENV["AUDIENCE"]}users`, {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
      "Authorization": token,
    },
    body: JSON.stringify(user_credentials),
  });
  return await data.json();
};

const token = await getToken();

console.log("\nTOKEN:");
console.log(token);

const user = await createUser(token);

console.log("\nUSER:");
console.log(user);
