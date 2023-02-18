package com.example.teacherasistant.viewmodels

import android.content.Context
import androidx.lifecycle.ViewModel
import androidx.lifecycle.viewModelScope
import com.example.teacherasistant.database.AppDatabase
import com.example.teacherasistant.repositories.AppRepository
import kotlinx.coroutines.launch

class MainViewModel(private val _context: Context) : ViewModel() {
    private val _appRepository = AppRepository(
        AppDatabase.getInstance(_context).subjectDao(),
        AppDatabase.getInstance(_context).studentDao(),
        AppDatabase.getInstance(_context).markDao()
    )

    fun deleteAllSubjects() = viewModelScope.launch {
        _appRepository.deleteAllSubjects()
    }

    fun deleteAllSubjectsWithStudents() = viewModelScope.launch {
        _appRepository.deleteAllSubjectsWithStudents()
    }

    fun deleteAllStudents() = viewModelScope.launch {
        _appRepository.deleteAllStudents()
    }

    fun deleteAllMarks() = viewModelScope.launch {
        _appRepository.deleteAllMarks()
    }
}