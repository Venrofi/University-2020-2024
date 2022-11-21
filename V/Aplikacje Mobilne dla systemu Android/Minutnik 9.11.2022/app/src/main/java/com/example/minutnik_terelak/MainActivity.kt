package com.example.minutnik_terelak

import android.annotation.SuppressLint
import android.os.Bundle
import android.os.CountDownTimer
import android.view.Gravity
import android.view.View
import android.widget.Button
import android.widget.TextView
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import java.lang.Integer.parseInt

class MainActivity : AppCompatActivity() {

    private lateinit var startButton: Button
    private lateinit var resetButton: Button
    private lateinit var stopButton: Button

    private lateinit var firstMinute: TextView
    private lateinit var lastMinute: TextView
    private lateinit var firstSecond: TextView
    private lateinit var lastSecond: TextView

    private lateinit var firstMinutePlusButton: Button
    private lateinit var lastMinutePlusButton: Button
    private lateinit var firstSecondPlusButton: Button
    private lateinit var lastSecondPlusButton: Button

    private lateinit var firstMinuteMinusButton: Button
    private lateinit var lastMinuteMinusButton: Button
    private lateinit var firstSecondMinusButton: Button
    private lateinit var lastSecondMinusButton: Button

    private var listOfButtons = listOf<Button>()

    private lateinit var countDownTimer: CountDownTimer
    var timeLeftInMillis: Long = 0
    var isRunning: Boolean = false

    @SuppressLint("SetTextI18n")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        startButton = findViewById(R.id.startButton)
        resetButton = findViewById(R.id.resetButton)
        stopButton = findViewById(R.id.stopButton)

        firstMinute = findViewById(R.id.firstMinute)
        lastMinute = findViewById(R.id.lastMinute)
        firstSecond = findViewById(R.id.firstSecond)
        lastSecond = findViewById(R.id.lastSecond)

        firstMinutePlusButton = findViewById(R.id.firstMinutePlusButton)
        lastMinutePlusButton = findViewById(R.id.lastMinutePlusButton)
        firstSecondPlusButton = findViewById(R.id.firstSecondPlusButton)
        lastSecondPlusButton = findViewById(R.id.lastSecondPlusButton)

        firstMinuteMinusButton = findViewById(R.id.firstMinuteMinusButton)
        lastMinuteMinusButton = findViewById(R.id.lastMinuteMinusButton)
        firstSecondMinusButton = findViewById(R.id.firstSecondMinusButton)
        lastSecondMinusButton = findViewById(R.id.lastSecondMinusButton)

        listOfButtons = listOf(
            firstMinutePlusButton,
            lastMinutePlusButton,
            firstSecondPlusButton,
            lastSecondPlusButton,
            firstMinuteMinusButton,
            lastMinuteMinusButton,
            firstSecondMinusButton,
            lastSecondMinusButton
        )

        startButton.setOnClickListener { startTimer() }
        stopButton.setOnClickListener { stopTimer() }
        resetButton.setOnClickListener { resetTimer() }

        firstMinutePlusButton.setOnClickListener {
            if (firstMinute.text == "5") {
                firstMinute.text = "0"
            } else {
                firstMinute.text = (parseInt(firstMinute.text as String) + 1).toString()
            }
        }
        firstMinuteMinusButton.setOnClickListener {
            if (firstMinute.text == "0") {
                firstMinute.text = "5"
            } else {
                firstMinute.text = (parseInt(firstMinute.text as String) - 1).toString()
            }
        }

        lastMinutePlusButton.setOnClickListener {
            if (lastMinute.text == "9") {
                lastMinute.text = "0"
                if(firstMinute.text != "5"){
                    firstMinute.text = (parseInt(firstMinute.text as String) + 1).toString()
                }
            } else {
                lastMinute.text = (parseInt(lastMinute.text as String) + 1).toString()
            }
        }
        lastMinuteMinusButton.setOnClickListener {
            if (lastMinute.text == "0") {
                lastMinute.text = "9"
            } else {
                lastMinute.text = (parseInt(lastMinute.text as String) - 1).toString()
            }
        }

        firstSecondPlusButton.setOnClickListener {
            if (firstSecond.text == "5") {
                firstSecond.text = "0"
                if(lastMinute.text != "9"){
                    lastMinute.text = (parseInt(lastMinute.text as String) + 1).toString()
                }
            } else {
                firstSecond.text = (parseInt(firstSecond.text as String) + 1).toString()
            }
        }
        firstSecondMinusButton.setOnClickListener {
            if (firstSecond.text == "0") {
                firstSecond.text = "5"
            } else {
                firstSecond.text = (parseInt(firstSecond.text as String) - 1).toString()
            }
        }

        lastSecondPlusButton.setOnClickListener {
            if (lastSecond.text == "9") {
                lastSecond.text = "0"
                if(firstSecond.text != "5"){
                    firstSecond.text = (parseInt(firstSecond.text as String) + 1).toString()
                }
            } else {
                lastSecond.text = (parseInt(lastSecond.text as String) + 1).toString()
            }
        }
        lastSecondMinusButton.setOnClickListener {
            if (lastSecond.text == "0") {
                lastSecond.text = "9"
            } else {
                lastSecond.text = (parseInt(lastSecond.text as String) - 1).toString()
            }
        }
        initialSetup()
    }

    private fun initialSetup(){
        startButton.isEnabled = true
        stopButton.isEnabled = false
        resetButton.isEnabled = true
        firstSecond.text = "0"
        firstMinute.text = "0"
        lastSecond.text = "0"
        lastMinute.text = "0"
        timeLeftInMillis = 0
        isRunning = false
    }

    private fun countTimeToMillis(): Long {
        var timeToMillis: Long = 0
        timeToMillis += (firstMinute.text as String).toLong() * 600000
        timeToMillis += (lastMinute.text as String).toLong() * 60000
        timeToMillis += (firstSecond.text as String).toLong() * 10000
        timeToMillis += (lastSecond.text as String).toLong() * 1000
        return timeToMillis
    }

    private fun updateCountDownText() {
        val minutes: Int = ((timeLeftInMillis / 1000) / 60).toInt()
        val seconds: Int = ((timeLeftInMillis / 1000) % 60).toInt()

        firstMinute.text = (minutes / 10).toString()
        lastMinute.text = (minutes % 10).toString()
        firstSecond.text = (seconds / 10).toString()
        lastSecond.text = (seconds % 10).toString()
    }

    private fun enableTimeManipulation() {
        for (button in listOfButtons){
            button.visibility = View.VISIBLE
        }
    }

    private fun disableTimeManipulation() {
        for (button in listOfButtons){
            button.visibility = View.INVISIBLE
        }
    }

    private fun startTimer(){
        timeLeftInMillis = countTimeToMillis()
        if(timeLeftInMillis <= 0) return

        startButton.isEnabled = false
        stopButton.isEnabled = true
        resetButton.isEnabled = false
        isRunning = true
        disableTimeManipulation()

        var finishMessage: Toast = Toast.makeText(applicationContext, "Time is up!", Toast.LENGTH_SHORT)

        countDownTimer = object : CountDownTimer(timeLeftInMillis, 1000) {
            override fun onTick(millisUntilFinished: Long) {
                timeLeftInMillis = millisUntilFinished
                updateCountDownText()
            }

            override fun onFinish() {
                enableTimeManipulation()
                finishMessage.show();
                initialSetup()
            }
        }.start()
    }

    private fun stopTimer(){
        startButton.isEnabled = true
        stopButton.isEnabled = false
        resetButton.isEnabled = true
        isRunning = false
        countDownTimer.cancel()
        enableTimeManipulation()
    }

    private fun resetTimer(){
        initialSetup()
    }

    override fun onSaveInstanceState(outState: Bundle) {
        super.onSaveInstanceState(outState)
        outState.putLong("timeLeft", timeLeftInMillis)
        outState.putBoolean("isRunning", isRunning)
    }

    override fun onRestoreInstanceState(savedInstanceState: Bundle) {
        super.onRestoreInstanceState(savedInstanceState)
        timeLeftInMillis = savedInstanceState.getLong("timeLeft")
        isRunning = savedInstanceState.getBoolean("isRunning")
        updateCountDownText()

        if (isRunning){
            startTimer()
        }
    }
}