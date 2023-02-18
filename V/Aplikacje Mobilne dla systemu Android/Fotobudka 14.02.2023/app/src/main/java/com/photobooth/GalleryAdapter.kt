package com.photobooth

import android.graphics.BitmapFactory
import android.graphics.Canvas
import android.graphics.Color
import android.graphics.Paint
import android.graphics.pdf.PdfDocument
import android.graphics.pdf.PdfDocument.PageInfo
import android.net.Uri
import android.os.Environment
import android.util.Log
import android.view.LayoutInflater
import android.view.ViewGroup
import android.widget.Toast
import androidx.recyclerview.widget.RecyclerView
import com.bumptech.glide.Glide
import com.photobooth.databinding.ListItemImgBinding
import java.io.File
import java.io.FileOutputStream
import java.io.IOException
import java.text.SimpleDateFormat
import java.util.*


class GalleryAdapter(private val fileArray: Array<File>) :
    RecyclerView.Adapter<GalleryAdapter.ViewHolder>() {
    class ViewHolder(private val binding: ListItemImgBinding) :
        RecyclerView.ViewHolder(binding.root) {
        fun bind(file: File) {
            Glide.with(binding.root).load(file).into(binding.localImg)
        }

    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): ViewHolder {
        val layoutInflater = LayoutInflater.from(parent.context)
        return ViewHolder(ListItemImgBinding.inflate(layoutInflater, parent, false))
    }

    override fun onBindViewHolder(holder: ViewHolder, position: Int) {
        holder.bind(fileArray[position])
    }

    override fun getItemCount(): Int {
        return fileArray.size
    }

    // nie wiem jak to podlaczyc tbh
    fun createPDFWithMultipleImage() {
        val file = getOutputFile()
        if (file != null) {
            try {
                val fileOutputStream = FileOutputStream(file)
                val pdfDocument = PdfDocument()
                for (i in fileArray.indices) {
                    val bitmap = BitmapFactory.decodeFile(fileArray.get(i).getPath())
                    val pageInfo = PageInfo.Builder(bitmap.width, bitmap.height, i + 1).create()
                    val page = pdfDocument.startPage(pageInfo)
                    val canvas: Canvas = page.canvas
                    val paint = Paint()
                    paint.setColor(Color.BLUE)
                    canvas.drawPaint(paint)
                    canvas.drawBitmap(bitmap, 0f, 0f, null)
                    pdfDocument.finishPage(page)
                    bitmap.recycle()
                }
                pdfDocument.writeTo(fileOutputStream)
                pdfDocument.close()
            } catch (e: IOException) {
                e.printStackTrace()
            }
        }
    }

   private fun getOutputFile(): File? {
        val uri: Uri = Uri.parse(Environment.getExternalStoragePublicDirectory(GalleryActivity().getExternalFilesDir(Environment.DIRECTORY_PICTURES).toString().replace("/storage/emulated/0", "")).path.toString())
        Log.e("INFO", uri.toString())
        val root: File = File(uri.path) // powinno byc uri ale wywala misstype; kod przerabiany z javy przez android studio wiec moga byc smaczki
        var isFolderCreated = true
        if (!root.exists()) {
            isFolderCreated = root.mkdir()
        }
        return if (isFolderCreated) {
            val timeStamp: String = SimpleDateFormat("yyyyMMdd_HHmmss", Locale.US).format(Date())
            val imageFileName = "PDF_$timeStamp"
            File(root, "$imageFileName.pdf")
        } else {
            //Toast.makeText(this, "Folder is not created", Toast.LENGTH_SHORT).show()
            null
        }
    }
}