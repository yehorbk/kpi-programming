import { config } from "https://deno.land/std/dotenv/mod.ts";

// load environment variables from .env file
const ENV = await config();

// generate x-www-form-urlencoded body
const encodeForm = (obj: Object) => {
  return Object.entries(obj)
    .reduce<string[]>((array, entry) => {
      const encodedKey = encodeURIComponent(entry[0]);
      const encodedValue = encodeURIComponent(entry[1]);
      array.push(`${encodedKey}=${encodedValue}`);
      return array;
    }, [])
    .join("&");
};

const getToken = async () => {
  const form = encodeForm({
    grant_type: "http://auth0.com/oauth/grant-type/password-realm",
    client_id: ENV["CLIENT_ID"],
    client_secret: ENV["CLIENT_SECRET"],
    audience: ENV["AUDIENCE"],
    realm: "Username-Password-Authentication",
    scope: "offline_access",
    username: ENV["EMAIL"],
    password: ENV["PASSWORD"],
  });
  const response = await fetch(`https://${ENV["DOMAIN"]}/oauth/token`, {
    method: "POST",
    headers: {
      "Content-Type": "application/x-www-form-urlencoded",
    },
    body: form,
  });
  const { access_token, refresh_token } = await response.json();
  return { access_token, refresh_token };
};

const refreshToken = async (refresh_token) => {
  const form = encodeForm({
    grant_type: "refresh_token",
    client_id: ENV["CLIENT_ID"],
    client_secret: ENV["CLIENT_SECRET"],
    refresh_token,
  });
  const response = await fetch(`https://${ENV["DOMAIN"]}/oauth/token`, {
    method: "POST",
    headers: {
      "Content-Type": "application/x-www-form-urlencoded",
    },
    body: form,
  });
  const { access_token } = await response.json();
  return access_token;
};

const { access_token, refresh_token } = await getToken();

console.log("\nACCESS TOKEN:");
console.log(access_token);

console.log("\nREFRESH TOKEN:");
console.log(refresh_token);

const refreshed_access_token = await refreshToken(refresh_token);

console.log("\nREFRESHED ACCESS TOKEN:");
console.log(refreshed_access_token);
