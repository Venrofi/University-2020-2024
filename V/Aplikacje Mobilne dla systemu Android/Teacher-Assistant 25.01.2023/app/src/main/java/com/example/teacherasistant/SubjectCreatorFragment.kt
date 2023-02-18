package com.example.teacherasistant

import android.content.Context
import android.os.Bundle
import androidx.fragment.app.Fragment
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.AdapterView
import android.widget.ArrayAdapter
import android.widget.Button
import android.widget.EditText
import android.widget.Spinner
import android.widget.TimePicker
import android.widget.Toast
import androidx.navigation.findNavController
import com.example.teacherasistant.database.entities.Subject
import com.example.teacherasistant.viewmodels.SubjectCreatorViewModel

/**
 * A simple [Fragment] subclass.
 */
class SubjectCreatorFragment : Fragment(), AdapterView.OnItemSelectedListener {
    private lateinit var _subjectCreatorViewModel: SubjectCreatorViewModel

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        // Inflate the layout for this fragment
        val view = inflater.inflate(R.layout.fragment_subject_creator, container, false)

        _subjectCreatorViewModel = SubjectCreatorViewModel(activity as Context)

        val nameEditText: EditText = view.findViewById(R.id.subject_creator_name_edit_text)

        val daySpinner: Spinner = view.findViewById(R.id.subject_creator_day_spinner)
        daySpinner.onItemSelectedListener = this

        ArrayAdapter.createFromResource(
            activity as Context,
            R.array.days,
            R.layout.my_spinner_item
        ).also { adapter ->
            adapter.setDropDownViewResource(R.layout.my_dropdown_spinner_item)
            daySpinner.adapter = adapter
        }

        val startTimePicker: TimePicker = view.findViewById(R.id.subject_creator_start_time_picker)
        startTimePicker.setIs24HourView(true)
        val endTimePicker: TimePicker = view.findViewById(R.id.subject_creator_end_time_picker)
        endTimePicker.setIs24HourView(true)

        val createSubjectButton: Button = view.findViewById(R.id.subject_creator_create_button)
        createSubjectButton.setOnClickListener {
            val startHour: Int = startTimePicker.hour
            val startMinute: Int = startTimePicker.minute
            val endHour: Int = endTimePicker.hour
            val endMinute: Int = endTimePicker.minute

            if (nameEditText.text.isNotEmpty() && ((startHour < endHour) ||
                        ((startHour == endHour) && (startMinute < endMinute)))
            ) {
                val startTime: String =
                    "${if (startHour < 10) "0$startHour" else "$startHour"}:" +
                            if (startMinute < 10) "0$startMinute" else "$startMinute"
                val endTime: String =
                    "${if (endHour < 10) "0$endHour" else "$endHour"}:" +
                            if (endMinute < 10) "0$endMinute" else "$endMinute"

                val subject = Subject(
                    null,
                    nameEditText.text.toString(),
                    daySpinner.selectedItem.toString(),
                    startTime,
                    endTime
                )

                _subjectCreatorViewModel.insertSubject(subject)

                view.findNavController().popBackStack()
            } else {
                Toast.makeText(
                    context,
                    "Nieprawidłowa nazwa lub blok godzinowy!",
                    Toast.LENGTH_SHORT
                ).show()
            }
        }

        return view
    }

    override fun onItemSelected(parent: AdapterView<*>, view: View?, pos: Int, id: Long) {
        // An item was selected. You can retrieve the selected item using
        // parent.getItemAtPosition(pos)
    }

    override fun onNothingSelected(parent: AdapterView<*>) {
        // Another interface callback
    }
}