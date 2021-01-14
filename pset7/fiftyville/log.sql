-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find information about crimes on 28 July 2020 on Chamberlin Street
SELECT * FROM crime_scene_reports WHERE street="Chamberlin Street" AND day=28 AND month=7 AND year=2020;

-- Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.

SELECT * FROM interviews WHERE day=28 AND month=7 AND transcript LIKE "%courthouse%";

-- Ruth Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.

-- Find all cars that were leaving the parking lot at 10 hours
SELECT * FROM courthouse_security_logs WHERE year=2020 AND month=7 AND day=28 AND hour=10 AND minute BETWEEN 15 AND 25 AND activity="exit";

--Eugene I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

-- Raymond	As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- Find information about people that were withdrawing money from ATM on Fifer Street on 28 July 2  020
SELECT * FROM people WHERE
id IN
    (SELECT person_id FROM bank_accounts WHERE account_number IN
        (SELECT account_number FROM atm_transactions WHERE year=2020 AND month=7 AND day=28 AND atm_location="Fifer Street" AND transaction_type="withdraw"))
AND license_plate IN
    (SELECT license_plate FROM courthouse_security_logs WHERE year=2020 AND month=7 AND day=28 AND hour=10 AND minute BETWEEN 15 AND 25 AND activity="exit")
AND phone_number IN
    (SELECT caller FROM phone_calls WHERE year=2020 AND month=7 AND day=28 AND duration < 60);



-- Find earliest flights from Fiftyville on 29 July 2020
SELECT * FROM flights JOIN airports ON airports.id=flights.origin_airport_id WHERE city="Fiftyville" AND year=2020 AND month=7 AND day=29 ORDER BY hour ASC LIMIT 2;


-- Find thief
SELECT * FROM people WHERE passport_number IN
    (SELECT passport_number FROM passengers WHERE flight_id IN
        (SELECT flights.id FROM flights JOIN airports ON airports.id=flights.origin_airport_id WHERE city="Fiftyville" AND year=2020 AND month=7 AND day=29 ORDER BY hour ASC LIMIT 2)
    AND passengers.passport_number IN
        (SELECT people.passport_number FROM people WHERE id IN
            (SELECT person_id FROM bank_accounts WHERE account_number IN
                (SELECT account_number FROM atm_transactions WHERE year=2020 AND month=7 AND day=28 AND atm_location="Fifer Street" AND transaction_type="withdraw"))
        AND license_plate IN
            (SELECT license_plate FROM courthouse_security_logs WHERE year=2020 AND month=7 AND day=28 AND hour=10 AND minute BETWEEN 15 AND 25 AND activity="exit")
        AND phone_number IN
            (SELECT caller FROM phone_calls WHERE year=2020 AND month=7 AND day=28 AND duration < 60)));

-- The thief is Ernest 686048


-- He is going to
SELECT city FROM airports WHERE id IN (SELECT destination_airport_id FROM flights WHERE id IN (SELECT flight_id FROM passengers WHERE passport_number IN (SELECT passport_number FROM people WHERE id = 686048)));

-- LONDON

-- Now let's find accomplice
SELECT * FROM people WHERE phone_number IN (SELECT receiver FROM phone_calls WHERE year=2020 AND month=7 AND day=28 AND duration < 60 AND caller IN (SELECT phone_number FROM people WHERE id = 686048));

-- It is Berthold 864400