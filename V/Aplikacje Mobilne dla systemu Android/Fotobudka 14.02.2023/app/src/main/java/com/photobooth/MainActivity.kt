package com.photobooth

import android.annotation.SuppressLint
import android.content.Intent
import android.graphics.Color
import android.graphics.drawable.ColorDrawable
import android.media.MediaActionSound
import android.os.Build
import android.os.Bundle
import android.util.Log
import android.view.View
import android.widget.AdapterView
import android.widget.ArrayAdapter
import android.widget.Toast
import androidx.activity.result.contract.ActivityResultContracts
import androidx.annotation.RequiresApi
import androidx.appcompat.app.AppCompatActivity
import androidx.camera.core.CameraSelector
import androidx.camera.core.ImageCapture
import androidx.camera.core.ImageCaptureException
import androidx.camera.core.Preview
import androidx.camera.lifecycle.ProcessCameraProvider
import androidx.core.content.ContextCompat
import androidx.core.net.toUri
import com.google.android.material.snackbar.Snackbar
import com.google.common.util.concurrent.ListenableFuture
import com.photobooth.databinding.ActivityMainBinding
import java.io.File
import java.util.concurrent.ExecutorService
import java.util.concurrent.Executors


class MainActivity : AppCompatActivity() {
    private lateinit var binding: ActivityMainBinding
    private lateinit var cameraProviderFuture: ListenableFuture<ProcessCameraProvider>
    private lateinit var cameraSelector: CameraSelector
    private var imageCapture: ImageCapture? = null
    private lateinit var imgCaptureExecutor: ExecutorService
    private val cameraPermissionResult =
        registerForActivityResult(ActivityResultContracts.RequestPermission()) { permissionGranted ->
            if (permissionGranted) {
                startCamera()
            } else {
                Snackbar.make(
                    binding.root,
                    "The camera permission is necessary",
                    Snackbar.LENGTH_INDEFINITE
                ).show()
            }
        }
    private val selectedNumber = arrayOf("1", "2", "3", "4")
    private val selectedSeconds = arrayOf("2 sekundy", "3 sekundy", "4 sekundy", "5 sekund")
    private var isActualTaking = false
    private var time:Long = 2;
    private val sound = MediaActionSound()
    private var mToast: Toast? = null

    @SuppressLint("ShowToast")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        supportActionBar?.hide();

        cameraProviderFuture = ProcessCameraProvider.getInstance(this)
        cameraSelector = CameraSelector.DEFAULT_BACK_CAMERA

        imgCaptureExecutor = Executors.newSingleThreadExecutor()

        cameraPermissionResult.launch(android.Manifest.permission.CAMERA)

        val spinner = binding.spinner
        val ArrayAdapter = ArrayAdapter(this, android.R.layout.simple_spinner_item, selectedNumber)
        spinner.adapter = ArrayAdapter
        spinner.onItemSelectedListener = object: AdapterView.OnItemSelectedListener{
            override fun onItemSelected(p0: AdapterView<*>?, p1: View?, p2: Int, p3: Long) {
                //Toast.makeText(applicationContext, "Wybrana ilosc to: " + selectedNumber[p2], Toast.LENGTH_SHORT).show()
            }

            override fun onNothingSelected(p0: AdapterView<*>?) {
                TODO("Not yet implemented")
            }
        }
        val spinner2 = binding.spinner2
        val ArrAdapter = ArrayAdapter(this, android.R.layout.simple_spinner_item, selectedSeconds)
        spinner2.adapter = ArrAdapter
        spinner2.onItemSelectedListener = object:AdapterView.OnItemSelectedListener{
            override fun onItemSelected(p0: AdapterView<*>?, p1: View?, p2: Int, p3: Long) {
                //Toast.makeText(applicationContext, "Wybrana ilosc to: " + selectedNumber[p2], Toast.LENGTH_SHORT).show()
                time = selectedSeconds[p2].subSequence(0,1).toString().toLong()
            }

            override fun onNothingSelected(p0: AdapterView<*>?) {
                TODO("Not yet implemented")
            }
        }


        binding.imgCaptureBtn.setOnClickListener {
            if(isActualTaking){
                Toast.makeText(applicationContext, "Aktualnie trwa sesja zdjęciowa", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }
            //Toast.makeText(applicationContext, "${time.toString().toLong()}", Toast.LENGTH_SHORT).show()
            isActualTaking = true
            sound.play(MediaActionSound.START_VIDEO_RECORDING)

            Thread{
                for(i in 0..spinner.selectedItemPosition){

                    //Thread.sleep(time * 1000)         // tu wersja bez odliczania

                    // tu z odliczaniem co sekunde
                    for(i in time-1 downTo 0){
                        Thread.sleep(1000)
                        sound.play(MediaActionSound.FOCUS_COMPLETE)

                        //tu toast, co pokazuje ile czasu do zdjecia, jak zbedne to do usuniecia
                        this@MainActivity.runOnUiThread(Runnable {
                            if(mToast != null){
                                mToast?.cancel()
                            }
                            mToast = Toast.makeText(applicationContext, "${i + 1}", Toast.LENGTH_SHORT)
                            mToast?.show()
                        })
                    }

                    Thread.sleep(1000)

                    sound.play(MediaActionSound.SHUTTER_CLICK)
                    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
                        animateFlash()
                    }
                    takePhoto()
                }
                isActualTaking = false;
                Thread.sleep(1000)
                sound.play(MediaActionSound.STOP_VIDEO_RECORDING)
            }.start()

        }

        binding.switchBtn.setOnClickListener {
            if(isActualTaking){
                Toast.makeText(applicationContext, "Aktualnie trwa sesja zdjęciowa", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }
            cameraSelector = if (cameraSelector == CameraSelector.DEFAULT_BACK_CAMERA) {
                CameraSelector.DEFAULT_FRONT_CAMERA
            } else {
                CameraSelector.DEFAULT_BACK_CAMERA
            }
            startCamera()
        }
        binding.galleryBtn.setOnClickListener {
            if(isActualTaking){
                Toast.makeText(applicationContext, "Aktualnie trwa sesja zdjęciowa", Toast.LENGTH_SHORT).show()
                return@setOnClickListener
            }
            val intent = Intent(this, GalleryActivity::class.java)
            startActivity(intent)
        }



    }

    private fun startCamera() {
        val preview = Preview.Builder().build().also {
            it.setSurfaceProvider(binding.preview.surfaceProvider)
        }
        cameraProviderFuture.addListener({
            val cameraProvider = cameraProviderFuture.get()

            imageCapture = ImageCapture.Builder().build()

            try {
                cameraProvider.unbindAll()
                cameraProvider.bindToLifecycle(this, cameraSelector, preview, imageCapture)
            } catch (e: Exception) {
                Log.d(TAG, "Use case binding failed")
            }
        }, ContextCompat.getMainExecutor(this))
    }

    private fun takePhoto() {
        imageCapture?.let {
            val fileName = "JPEG_${System.currentTimeMillis()}"
            val file = File(externalMediaDirs[0], fileName)
            val outputFileOptions = ImageCapture.OutputFileOptions.Builder(file).build()
            it.takePicture(
                outputFileOptions,
                imgCaptureExecutor,
                object : ImageCapture.OnImageSavedCallback {
                    override fun onImageSaved(outputFileResults: ImageCapture.OutputFileResults) {
                        Log.i(TAG, "The image has been saved in ${file.toUri()}")
                    }

                    override fun onError(exception: ImageCaptureException) {
                        Toast.makeText(
                            binding.root.context,
                            "Error taking photo",
                            Toast.LENGTH_LONG
                        ).show()
                        Log.d(TAG, "Error taking photo:$exception")
                    }

                })
        }
    }

    @RequiresApi(Build.VERSION_CODES.M)
    private fun animateFlash() {
        binding.root.postDelayed({
            binding.root.foreground = ColorDrawable(Color.WHITE)
            binding.root.postDelayed({
                binding.root.foreground = null
            }, 50)
        }, 100)
    }

    companion object {
        val TAG = "MainActivity"
    }
}