package com.example.teacherasistant.database

import android.content.Context
import androidx.room.Database
import androidx.room.Room
import androidx.room.RoomDatabase
import com.example.teacherasistant.database.daos.MarkDao
import com.example.teacherasistant.database.daos.StudentDao
import com.example.teacherasistant.database.daos.SubjectDao
import com.example.teacherasistant.database.entities.Mark
import com.example.teacherasistant.database.entities.Student
import com.example.teacherasistant.database.entities.Subject
import com.example.teacherasistant.database.entities.SubjectStudentCrossRef

@Database(
    entities = [Subject::class, Student::class, SubjectStudentCrossRef::class, Mark::class],
    version = 1
)
abstract class AppDatabase : RoomDatabase() {
    abstract fun subjectDao(): SubjectDao
    abstract fun studentDao(): StudentDao
    abstract fun markDao(): MarkDao

    companion object {
        private var _instance: AppDatabase? = null

        fun getInstance(context: Context): AppDatabase {
            if (_instance == null) {
                synchronized(this) {
                    _instance = Room.databaseBuilder(
                        context,
                        AppDatabase::class.java,
                        "teacher_asistant_database"
                    ).build()
                }
            }

            return _instance!!
        }
    }
}