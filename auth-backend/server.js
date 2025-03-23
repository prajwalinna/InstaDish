require("dotenv").config(); //this will load env file into this for db ka pass and jwt
const express = require("express");
const mongoose = require("mongoose");
const cors = require("cors");

const app = express();
app.use(express.json());
app.use(cors());

//need to connect to mongodb
mongoose
  .connect(process.env.MONGO_URI)
  .then(() => console.log("MongoDb connected"))
  .catch((err) => console.log(err));

app.get("/", (req, res) => {
  res.send("Authorization API is running...");
});
const authRoutes = require("./routes/authRoutes");
app.use("/api/auth", authRoutes);

const PORT = process.env.PORT || 5000;
app.listen(PORT, () => console.log(`Server running on port ${PORT}`));
