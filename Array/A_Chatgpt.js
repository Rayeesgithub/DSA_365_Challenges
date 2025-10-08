🔒 Advanced-Level Questions

How do you refresh expired JWT tokens using a refresh token system?

What happens if a JWT token is stolen — how can you prevent misuse?

What’s the best way to revoke a JWT token?

Why shouldn’t you store sensitive data inside JWT payload?

How do you implement logout functionality when using JWT?

What’s the difference between stateless and stateful authentication?

How do you handle token expiration on the frontend and backend?

How can you make your JWT more secure using asymmetric encryption (RS256)?

What are the security risks of storing tokens in localStorage vs cookies?

Can you manually decode JWT without verifying it? What’s the risk?

How do you handle JWT in microservices communication?

What’s the difference between Bearer token and Cookie-based authentication?

How do you implement role-based authentication with JWT?

🧩 Practical / Scenario-Based Questions

How would you implement login and signup routes using JWT?

How would you protect routes like /profile so only logged-in users can access them?

How do you check the user’s identity on every API request?

How do you store JWT securely in a cookie and retrieve it later?

How do you implement automatic logout when the token expires?

If two users use the same browser, how would you handle separate cookies?

How would you handle JWT invalidation when a user changes their password?

How would you secure tokens in production (HTTPS, SameSite, Secure flags)?

What’s the difference between jwt.sign() and jwt.verify() methods?

How would you test JWT-protected routes in Postman?

🧠 Conceptual Difference Questions

JWT vs OAuth 2.0

JWT vs Session + Cookies

Access Token vs Refresh Token

Token-based vs Cookie-based authentication

Stateless Authentication vs Stateful Authentication





























Copiolot->

  Cookies, storage, and client security
Question: Why store tokens in cookies instead of localStorage/sessionStorage?

Question: What are HttpOnly, Secure, and SameSite flags, and how do they protect cookies?

Question: When would you use SameSite=Lax vs Strict vs None?

Question: How do you set cookie domain and path safely for multi‑subdomain apps?

Question: What are the risks of XSS with token storage, and how do cookies help?

Question: How do you defend against CSRF when using cookies for auth?

Question: What’s the role of CSRF tokens or double‑submit cookies in JWT cookie flows?

Question: Is it safe to store refresh tokens in HttpOnly cookies and access tokens in memory?

Question: How do you clear cookies on logout across multiple domains?

Question: How do you handle “Remember Me” with cookies without weakening security?

  Route protection and session management
Question: How do you protect routes in Express using middleware for JWT verification?

Question: How do you implement role‑based access control (RBAC) with JWT claims?

Question: How do you protect admin‑only routes while keeping user routes accessible?

Question: What’s the best way to attach user context (id, roles) to req after verification?

Question: How do you protect WebSocket connections using JWT?

Question: How do you handle CORS in a cookie‑based JWT setup?

Question: How do you issue access and refresh tokens at login for a smooth UX?

Question: How do you refresh an access token when it expires, using a secure endpoint?

Question: How do you prevent replay attacks with refresh tokens?

Question: How do you implement device‑aware sessions (multi‑device login management)


Security hardening and threat modeling
Question: What attacks do JWTs and cookies need to defend against (XSS, CSRF, replay, token theft)?

Question: Why should you avoid putting sensitive data in JWT payloads?

Question: How do you enforce TLS everywhere and what breaks without it?

Question: How do you rate‑limit login and token refresh endpoints?

Question: How do you detect and block brute force attempts on login?

Question: How do you blacklist compromised refresh tokens?

Question: How do you implement an allowlist/denylist for token jti (IDs)?

Question: How do you secure your signing keys (env vars, KMS/HSM, rotation)?

Question: How do you prevent session fixation in cookie‑based auth?

Question: What headers (CSP, X‑Frame‑Options, Referrer‑Policy) help reduce attack surface?



  Implementation details and best practices
Question: Show Express middleware to sign access and refresh tokens on login.

Question: How do you validate JWTs in Express with a shared secret vs public key?

Question: How do you structure a refresh endpoint (checks, rotation, invalidation)?

Question: How do you implement logout with server‑side refresh token invalidation?

Question: How do you store refresh tokens (DB table, Redis) with expiry and single‑use?

Question: How do you implement token rotation to prevent replay after theft?

Question: How do you handle partial failures (access token expired but refresh valid)?

Question: How do you return consistent error codes/messages for unauthorized vs forbidden?

Question: How do you design middleware order (CORS → cookies → CSRF → auth → RBAC)?

Question: How do you handle clock skew in exp/nbf validations?

Question: How do you minimize token size while retaining necessary claims?
