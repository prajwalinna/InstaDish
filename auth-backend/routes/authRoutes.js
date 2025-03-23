const express = require("express");
const bcrypt = require("bcryptjs");
const User = require("../models/user");
// const user = require("../models/user");

const router = express.Router();

router.post("/signup", async (req, res) => {
  try {
    const { name, email, password } = req.body;

    let user = await User.findOne({ email });
    if (user) return res.status(400).json({ message: "User already exists" });

    const salt = await bcrypt.genSalt(10);
    const hashedPassword = await bcrypt.hash(password, salt);

    user = new User({ name, email, password: hashedPassword });
    await user.save();
    res.status(201).json({ message: "User registered successfully" });
  } catch (error) {
    // res.status(500).json({ message: "Error" });
    console.error("Signup Error:", error);
    res.status(500).json({ message: "Server error", error: error.message });
  }
});
module.exports = router;
